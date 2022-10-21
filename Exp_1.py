# Practical 1
#

#%%
# Import Libraries
import matplotlib.pyplot as plt
import numpy as np
import cv2

#%%
# Import Original Image
i=cv2.imread('C:\Users\sanke\OneDrive - DR BABASAHEB AMBEDKAR TECHNOLOGICAL UNIVERSITY LONERE\Desktop\DIP\Original.jpeg',cv2.IMREAD_UNCHANGED)
plt.subplot(3,2,1); plt.imshow(i); plt.title('Original Image');

#%%
# Blue Component
b=i[:,:,0]
plt.subplot(3,2,2); plt.imshow(b);plt.title('Blue Component');
cv2.imwrite('Blue.jpg',b) 

#%%
# Green Component
g=i[:,:,1]
plt.subplot(3,2,3); plt.imshow(g);plt.title('Green Component');
cv2.imwrite('Green.jpg',g) 

#%%
# Red Component
r=i[:,:,2]
plt.subplot(3,2,4); plt.imshow(r);plt.title('Red Component');
cv2.imwrite('Red.jpg',r) 

#%%
#GrayScale Image
imgGray = cv2.imread('F:\DIP-Lab\Org_Img.jpg',0)
plt.subplot(3,2,5); plt.imshow(imgGray);plt.title('Gray Scale');
cv2.imwrite('Gray.jpg',imgGray)