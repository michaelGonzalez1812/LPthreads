import time, threading,_thread, random
from tkinter import *
from tkinter import messagebox


def test():
    cont = 7
    cont1 = 0
    while(TRUE):
        if(cont < 1):
            cont = 7
            cont1 += 1
        elif(cont1 > 2):
            cont1 = 0
        # archivo 1
        f = open("../Bandas/Banda1.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont1)+","+str(cont))
        f.close()
        cont -= 1
        time.sleep(3)

test() 