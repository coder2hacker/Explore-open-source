# from lib2to3.pgen2 import driver
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options

op=Options()
op.add_experimental_option("debuggerAddress","localhost:1234")
driver=webdriver.Chrome(executable_path="E:\selenium\chromedriver.exe",chrome_options=op)

# driver=webdriver.Chrome(executable_path="chromedriver.exe")
driver.maximize_window()
driver.get("https://www.instagram.com/")

# '''<div class=" _ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm">teju_1_7_1</div>

# <div class=" _ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm">teju_1_7_1</div>


# <div class=" _ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm">amol__39</div>'''


# follower=driver.find_element(By.XPATH,'''//div[@class=" _ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm"]''')
driver.implicitly_wait(5)

login=driver.find_element(By.XPATH,'''//input[@name="username"]''').send_keys("test@1234")
password=driver.find_element(By.XPATH,'''//input[@name="password" and @aria-label="Password"]''').send_keys("456845843")
# time.sleep(2)
driver.find_element(By.XPATH,"//button[text()='Log In']").click()

# bt=driver.find_element(By.XPATH,"//button")
# print(bt.text)