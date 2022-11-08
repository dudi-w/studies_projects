from urllib.request import urlopen
import json
import csv

def latest_ID_Jobs():
    latest_ID_jobs_requst = urlopen("https://hacker-news.firebaseio.com/v0/jobstories.json")
    latest_ID_jobs_list =json.loads( latest_ID_jobs_requst.read())
    return latest_ID_jobs_list
    

def get_dedails_jobs( ID_jobs_list):
    with open('dateJobs.csv', 'w', encoding='UTF8', newline='') as jobs_date:
        writer = csv.writer(jobs_date)
        
        for ID_jobs in ID_jobs_list:
            print (ID_jobs)

            with urlopen(f"https://hacker-news.firebaseio.com/v0/item/{ID_jobs}.json?print=pretty") as date_job:
                temp=json.loads( date_job.read())
            details_jobs=[]
            details_jobs.append( temp.get("id"))
            details_jobs.append( temp.get("title"))
            details_jobs.append( temp.get("url"))
            writer.writerow( details_jobs)
    print ("Your file is ready")
    #return dedails_jobs
    

def main():
    #ododo latest_Jobs()
    print(get_dedails_jobs(latest_ID_Jobs()))
    #print (latest_ID_Jobs())

if __name__ == "__main__":
    main()
