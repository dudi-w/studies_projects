import requests
import api_key

API_KEY = api_key.MY_API_KEY

def get_virustotal_info(file_hash):
    url = f'https://www.virustotal.com/vtapi/v2/file/report'
    params = {'apikey': API_KEY, 'resource': file_hash}
    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        if data['response_code'] == 1:
            return data
        else:
            print(f"Error: {data['response_code']}")
            return None
    else:
        print(f"Error: {response.status_code}")
        return None

def create_markdown_table(file_hash):
    vt_info = get_virustotal_info(file_hash)
    if vt_info is not None:
        file_info_table =f"**File information:**\n| _MD5_ |  _SHA-1_ | _SHA-256_ |\\n|:----- | :------ | :-------- |\n| {vt_info['md5']} | {vt_info['sha1']} | {vt_info['sha256']} |\n"

        last_analysis_status_table = f"**Last Analysis ResultsFile information:**\n| _Total Scans_ | _Malicious Scans_ |\n|:------------- | :---------------- |\n|{vt_info['total']} | {vt_info['positives']}\n"

        last_analysis_results_table = f"**Last Analysis Results:**\n| _Scan Origin (name)_ | _Scan Result (category)_ |\n|:-------------------- | :----------------------- |\n"
        for scan, values in vt_info['scans'].items():
            last_analysis_results_table += f"| {scan} | {values['result']} |\n"

        return file_info_table +'\n'+ last_analysis_status_table +'\n'+ last_analysis_results_table
    else:
        return None

if __name__ == "__main__":
    file_hash = '84c82835a5d21bbcf75a61706d8ab549'
    analysis_results = create_markdown_table(file_hash)

    if analysis_results is not None:
        print(analysis_results)
