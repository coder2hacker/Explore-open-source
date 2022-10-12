from lib2to3.pgen2 import driver
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver=webdriver.Edge(executable_path="msedgedriver.exe")
driver.get("https://web.facebook.com")
time.sleep(3)




emial=driver.find_element(By.XPATH,"//*[@id='email']").send_keys("TEST@gmail.com")
password=driver.find_element(By.XPATH,'''//*[@id="pass"]''').send_keys("1234556789786767")
driver.find_element(By.XPATH,'''//*[@name="login"]''').click()

