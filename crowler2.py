import requests
from PIL import Image
import shutil
import urllib
from bs4 import BeautifulSoup
import os
import random

def downloand_pic( img_url , destination_directory ):
    print ("22")
    print (img_url)
    try:
        response = requests.get(img_url)
        if response.status_code:
            img_name = img_url.split('/')[-1]
            #file_name = main_page.split('/')[-1]
            #os.mkdir(f'{destination_directory}/{file_name}') 
            fp = open(f'{destination_directory}/{img_name}', 'wb')
            fp.write(response.content)
            fp.close()
    except:
        print("Invalid URL link")
        print(img_url )
    return



def get_url_img_from_url_page(url_page):
    print ("33")
    headers = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "en-GB,en-US;q=0.9,en;q=0.8",
    "Dnt": "1",
    "Host": "httpbin.org",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36",
    }
    
    #html_doc = requests.get(url_page ,headers=headers ).text

    html_doc = requests.get(url_page).text
    soup = BeautifulSoup(html_doc, 'html.parser')
    urls_img =[]
    for link in soup.find_all('img'):
        #print (link)
        x = fix_url(link.get('src'))
        print (x)
        if x not in urls_img and x is not None:
            urls_img.append(x)
            print (x)
    return urls_img


def create_download_directory( main_page, destination_directory ):
    print ("66")
    file_name = main_page.split('/')[-1]
    sub_destination_directory = (f'{destination_directory}/{file_name}' )
    try:
        os.mkdir(f'{sub_destination_directory}')
    except:
        os.mkdir(f'{sub_destination_directory}1')
    return sub_destination_directory

def get_url_from_main_page( main_page , width ):
    print ("55")
    html_doc = requests.get(url = main_page ).text
    soup = BeautifulSoup(html_doc, 'html.parser')
    urls_page=[]
    for link in soup.find_all('a'):
        #print ( link.get('href') )
        x = fix_url(link.get('href'))
        if x is not None:
            #print(x)
            urls_page.append(x)
    
    #Randomly selects a "url link" from the list, according to the width limit
    selected_url=[]
    for i in range( min( width , len(urls_page))):
        x = urls_page[random.randrange( len(urls_page))]
        if x not in selected_url:
            selected_url.append(x)
    return selected_url

def fix_url(url_link):
    print ("44")
    print (url_link)
    try:    
        if url_link.startswith("https") or url_link.startswith("http"):
            print (url_link)
            return url_link
        elif url_link.startswith("/wiki") or url_link.startswith("/static"):
            print ("https://en.wikipedia.org"+url_link)
            return "https://en.wikipedia.org"+url_link
        elif url_link.startswith("//upload"):
            print ("https:"+url_link)
            return "https:"+url_link
    except:
        return None

def controller(main_page , destination_directory , width , depth):
    print("11")
    list_url_img = get_url_img_from_url_page( main_page) 
    sub_destination_directory = create_download_directory( main_page , destination_directory)
    print (list_url_img )
    for url_img in list_url_img:
        downloand_pic( url_img , sub_destination_directory )

    urls_page = get_url_from_main_page( main_page , width)
    if depth >= 1 :
        for url_page in urls_page:
            controller(url_page , sub_destination_directory , width , depth-1 )



def main():
    main_page = "https://en.wikipedia.org/wiki/Israel_Defense_Forces"
    destination_directory = '/home/mefathim/Downloads'
    width = 2
    depth = 2
    controller(main_page , destination_directory , width , depth)
    #list_url_img = get_url_img_from_url_page( main_page )
    #sub_destination_directory = create_download_directory( main_page , '/home/mefathim/Downloads')
    #get_url_from_main_page( main_page , 2)
    #for url_img in list_url_img:
    #    downloand_pic( url_img , sub_destination_directory )
    

if __name__ == "__main__":
    main()

