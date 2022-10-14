'''QR Code Generator'''

import pyqrcode
text = input('Enter the link or text you want to convert to qr-code')
qr = pyqrcode.create(text)
qr.png("qrcode.png",scale=2)
qr.show()

'''Code provided by Akshaj Vishwanathan'''          
