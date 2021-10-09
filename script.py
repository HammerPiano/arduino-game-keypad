Import("env", "projenv")

env.ProcessUnFlags("-DUSB_VID=0x2341")
env.ProcessUnFlags("-DUSB_PID=0x8037")
env.ProcessUnFlags('-DUSB_PRODUCT="Arduino Micro"') 
env.ProcessUnFlags('-DUSB_MANUFACTURER="Arduino LLC"')

env.Append(CPPDEFINES=("USB_VID", 0x044F))
env.Append(CPPDEFINES=("USB_PID", 0xB351))
env.Append(CPPDEFINES=("USB_PRODUCT", '\\"Cougar MFD 1\\"'))
env.Append(CPPDEFINES=("USB_MANUFACTURER", '\\"Thrustmaster LLC\\"'))
