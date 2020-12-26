from bs4 import BeautifulSoup
import requests
import sys
import os

filename = sys.argv[1]
problem = filename.split(".")[0]
path = sys.argv[2]

print("Downloading page...")
page = requests.get("https://dmoj.ca/problem/" + problem)
print("Page downloaded!")
soup = BeautifulSoup(page.content, 'html.parser')
print("Extracting test data for problem " + soup.title.text)
testdata = soup.select(".content-description pre code")
print("Done!")
tl = soup.select("span.pi-value")[1].text.split("s")[0]
tcfilename = ".\\" + path + "\\" + problem + ".tc"

print("Creating .tc file")
if os.path.exists(tcfilename):
    deletecase = input("A test case file already exists. Do you wish to remove it? [y/N] ")
    if deletecase.lower() == "y":
        os.remove(tcfilename)
f = open(tcfilename, "w")
f.write(str(int(len(testdata)/2)) + "\n" + tl + "\n")

for i in range(0, len(testdata), 2):
    test = testdata[i].text
    result = testdata[i+1].text
    f.write(test + "\nbegin results\n" + result + "\nend case\n")
print("Finished!")

f.close()

