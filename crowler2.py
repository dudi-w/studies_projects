import requests
from PIL import Image
import shutil
import urllib
from bs4 import BeautifulSoup
import os
import random

def downloand_pic( img_url , destination_directory ):
    try:
        response = requests.get(img_url)
        if response.status_code:
            img_name = img_url.split('/')[-1]
            fp = open(f'{destination_directory}/{img_name}', 'wb')
            fp.write(response.content)
            fp.close()
    except:
        print("Invalid URL link")
        print(img_url )
    return



def get_url_img_from_url_page(url_page):
    html_doc = requests.get(url_page).text
    soup = BeautifulSoup(html_doc, 'html.parser')
    urls_img =[]
    for link in soup.find_all('img'):
        x = fix_url(link.get('src'))
        if x not in urls_img and x is not None:
            urls_img.append(x)
    return urls_img


def create_download_directory( main_page, destination_directory ):
    file_name = main_page.split('/')[-1]
    sub_destination_directory = (f'{destination_directory}/{file_name}' )
    try:
        os.mkdir(f'{sub_destination_directory}')
    except:
        os.mkdir(f'{sub_destination_directory}1')
    return sub_destination_directory

def get_url_from_main_page( main_page , width ):
    html_doc = requests.get(url = main_page ).text
    soup = BeautifulSoup(html_doc, 'html.parser')
    urls_page=[]
    for link in soup.find_all('a'):
        x = fix_url(link.get('href'))
        if x is not None:
            urls_page.append(x)
    
    #Randomly selects a "url link" from the list, according to the width limit
    selected_url=[]
    for i in range( min( width , len(urls_page))):
        x = urls_page[random.randrange( len(urls_page))]
        if x not in selected_url:
            selected_url.append(x)
    return selected_url

def fix_url(url_link):
    try:    
        if url_link.startswith("https") or url_link.startswith("http"):
            return url_link
        elif url_link.startswith("/wiki") or url_link.startswith("/static"):
            return "https://en.wikipedia.org"+url_link
        elif url_link.startswith("//upload"):
            return "https:"+url_link
    except:
        return None

def controller(main_page , destination_directory , width , depth):
    list_url_img = get_url_img_from_url_page( main_page) 
    sub_destination_directory = create_download_directory( main_page , destination_directory)
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
 
    

if __name__ == "__main__":
    main()

