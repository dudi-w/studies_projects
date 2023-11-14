import requests
import api_key


class VirusTotalError(Exception):
    pass


def create_markdown_table(title, list_headers, list_data):
    len_headers = len(list_headers)
    len_data = len(list_data)
    table = f'**{title}**\n|'
    for header in list_headers:
        table += f' _{header}_ |'
    table += '\n|'
    for _ in range(len_headers):
        table += ' :--- |'
    table += '\n'
    for i in range(int(len_data/len_headers)):
        for j in range(len_headers):
            table += f'| {list_data[(i*len_headers) + j]} '
        table += '|\n'
    table += '\n'
    return table


def get_virustotal_info(file_hash):
    url = 'https://www.virustotal.com/api/v3/files/' + file_hash
    headers = {
        "accept": "application/json",
        "x-apikey": api_key.MY_API_KEY
    }

    try:
        response = requests.get(url, headers=headers)
    except requests.exceptions.RequestException as e:
        raise VirusTotalError(f'Failed to establish a connection: {e}')

    if response.status_code == 200:
        data = response.json()
        return data
    else:
        raise VirusTotalError(f"HTTP error: {response.status_code}")


def create_markdown_file_info_table(virustotal_info):
    attributes = virustotal_info['data']['attributes']
    title = 'File information'
    list_headers = ['MD5', 'SHA-1', 'SHA-256']
    list_data = [attributes['md5'], attributes['sha1'], attributes['sha256']]
    return create_markdown_table(title, list_headers, list_data)


def create_markdown_last_analysis_status_table(virustotal_info):
    last_analysis_stats = virustotal_info['data']['attributes']['last_analysis_stats']
    title = 'Last Analysis Status'
    list_headers = ['Total Scans', 'Malicious Scans']
    list_data = [sum(last_analysis_stats.values()),
                 last_analysis_stats['malicious']]
    return create_markdown_table(title, list_headers, list_data)


def create_markdown_last_analysis_results_table(virustotal_info):
    last_analysis_results = virustotal_info['data']['attributes']['last_analysis_results']
    title = 'Last Analysis Results'
    list_headers = ['Scan Origin (name)', 'Scan Result (category)']
    list_data = []
    for scan, values in last_analysis_results.items():
        list_data.append(scan)
        list_data.append(values['result'])
    return create_markdown_table(title, list_headers, list_data)


def create_markdownan_alysis_results_table(target_file_hash):
    try:
        virustotal_info = get_virustotal_info(target_file_hash)
        table1 = create_markdown_file_info_table(virustotal_info)
        table2 = create_markdown_last_analysis_status_table(virustotal_info)
        table3 = create_markdown_last_analysis_results_table(virustotal_info)

        return table1 + table2 + table3
    except KeyError as e:
        raise VirusTotalError(
            f'Failed to access the key : {e}, check your key')


if __name__ == "__main__":
    file_hash = '84c82835a5d21bbcf75a61706d8ab549'
    try:
        analysis_results = create_markdownan_alysis_results_table(file_hash)
        print(analysis_results)
    except Exception as e:
        print(f'EREOR: {e}')
