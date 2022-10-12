from lib2to3.pgen2 import driver
from selenium.webdriver.common.by import By
from selenium import webdriver

driver=webdriver.Edge(executable_path="msedgedriver.exe")
# driver=webdriver.Edge(executable_path="C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe")
driver.get("https://www.facebook.com")
driver.maximize_window()


driver.find_element("name","email").send_keys("temp@gmail.com")
# name.send_keys("this is the test purpose")
driver.find_element("name","pass").send_keys("36483254365")
# password.send_keys("1234456")



# driver.find_element(By.LINK_TEXT,"Forgotten password?").click() #for getting text link and click it to further use
driver.find_element(By.LINK_TEXT,"Log in").click()




