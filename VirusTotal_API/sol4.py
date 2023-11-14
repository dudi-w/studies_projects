import requests
import api_key

API_KEY = api_key.MY_API_KEY


class VirusTotalError(Exception):
    pass


class VirusTotalAPI:
    def __init__(self, base_url, api_key):
        self.base_url = base_url
        self.api_key = api_key

    def get_file_report(self, file_hash):
        params = {'apikey': self.api_key, 'resource': file_hash}

        try:
            response = requests.get(self.base_url, params=params)
        except requests.exceptions.RequestException as e:
            raise VirusTotalError(f'Failed to establish a connection: {e}')

        if response.status_code == 200:
            data = response.json()
            print(data)
            if data['response_code'] == 1:
                return data
            else:
                raise VirusTotalError(
                    f"VirusTotal response code error: {data['response_code']}")
        else:
            raise VirusTotalError(f"HTTP error: {response.status_code}")


def create_markdown_file_info_table(virustotal_info):
    return f"**File information:**\n| _MD5_ |  _SHA-1_ | _SHA-256_ |\n|:----- | :------ | :-------- |\n| {virustotal_info['md5']} | {virustotal_info['sha1']} | {virustotal_info['sha256']} |\n"


def create_markdown_last_analysis_status_table(virustotal_info):
    return f"**Last Analysis Results:**\n| _Total Scans_ | _Malicious Scans_ |\n|:------------- | :---------------- |\n|{virustotal_info['total']} | {virustotal_info['positives']} |\n"


def create_markdown_last_analysis_results_table(virustotal_info):
    last_analysis_results_table = f"**Last Analysis Results:**\n| _Scan Origin (name)_ | _Scan Result (category)_ |\n|:-------------------- | :----------------------- |\n"
    for scan, values in virustotal_info['scans'].items():
        last_analysis_results_table += f"| {scan} | {values['result']} |\n"
    return last_analysis_results_table


def create_virustotal_info_table(target_file_hash):
    url = 'https://www.virustotal.com/vtapi/v2/file/report'
    api = VirusTotalAPI(url, api_key.MY_API_KEY)

    try:
        virustotal_info = api.get_file_report(target_file_hash)
        table1 = create_markdown_file_info_table(virustotal_info)
        table2 = create_markdown_last_analysis_status_table(virustotal_info)
        table3 = create_markdown_last_analysis_results_table(virustotal_info)

        return table1 + '\n' + table2 + '\n' + table3
    except VirusTotalError as e:
        raise e
    except requests.exceptions.RequestException as e:
        raise VirusTotalError(f'Failed to retrieve data from VirusTotal: {e}')


if __name__ == "__main__":
    file_hash = '84c82835a5d21bbcf75a61706d8ab549'
    try:
        analysis_results = create_virustotal_info_table(file_hash)
        print(analysis_results)
    except Exception as e:
        print(f'EREOR: {e}')
