import requests
import re
from colorama import Fore, Style


url = "https://www.virustotal.com/api/v3/files/84c82835a5d21bbcf75a61706d8ab549"

headers = {
    "accept": "application/json",
    "x-apikey": "85b5d8fdf945a335b844469928df10c3eb0d353a2a8d810f8934d43758fb6221"
}

response = requests.get(url, headers=headers)

# Function to colorize the word
def colorize_word(match):
    return f"{Fore.GREEN}{match.group(0)}{Style.RESET_ALL}"

# Specify the word you want to colorize
target_word = "result"


# Use regular expression to find and colorize the word
colored_text = re.sub("result", colorize_word, response.text, flags=re.IGNORECASE)
def colorize_word(match):
    return f"{Fore.BLUE}{match.group(0)}{Style.RESET_ALL}"
colored_text = re.sub("category", colorize_word, colored_text, flags=re.IGNORECASE)

# Print the colored text
print(colored_text)

# print(response.text)