from lib2to3.pgen2 import driver
from selenium import webdriver
from selenium.webdriver.common.by import By
import time
driver=webdriver.Edge(executable_path="msedgedriver.exe")
driver.maximize_window()
driver.get("https://web.whatsapp.com")


time.sleep(20)
t=input("enter the name :")
message=input("enter the message which you want to send the user:")
count=int(input("enter the digit .How many times you want to flood"))

for i in range(count):

    to=driver.find_element(By.XPATH,f"//span[@title='{t}']").click()

    driver.find_element(By.XPATH,'''/html/body/div[1]/div/div/div[4]/div/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[1]''').send_keys(f"{message}")

    driver.find_element(By.XPATH,'''/html/body/div[1]/div/div/div[4]/div/footer/div[1]/div/span[2]/div/div[2]/div[2]/button/span''').click()