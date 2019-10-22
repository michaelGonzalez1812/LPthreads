import time, threading,_thread, random
from tkinter import *
from tkinter import messagebox


def test():
    cont = 1
    cont1 = 0
    cont2 = 1
    cont3 = 2
    while(TRUE):
        if(cont >= 8):
            cont = 0
        # archivo 1
        f = open("../Bandas/Banda0.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont1)+","+str(cont))
        f.close()
        time.sleep(1)

        # archivo 1
        f = open("../Bandas/Banda1.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont2)+","+str(cont+1))
        f.close()
        time.sleep(1.5)

        # archivo 1
        f = open("../Bandas/Banda2.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont3)+","+str(cont+2))
        f.close()
        time.sleep(1.2)
        cont += 1

test() 