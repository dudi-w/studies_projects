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
            return None
    else:
        print(f"Error: {response.status_code}")
        return None

def create_markdown_table(file_hash):
    vt_info = get_virustotal_info(file_hash)
    if vt_info is not None:
        md_table = f"""
File information
MD5       SHA-1       SHA-256
{vt_info['md5']} {vt_info['sha1']} {vt_info['sha256']}

Last Analysis Status
Total Scans   Malicious Scans
{vt_info['total']}   {vt_info['positives']}

Last Analysis Results
Scan Origin (name)   Scan Result (category)
"""
        for scan, result in vt_info['scans'].items():
            md_table += f"{scan}     {result}\n"

        return md_table
    else:
        return "No information available for the provided file hash."

if __name__ == "__main__":
    file_hash = '84c82835a5d21bbcf75a61706d8ab549' 
    markdown_table = create_markdown_table(file_hash)
    print(markdown_table)
