import time, threading,_thread, random
from tkinter import *
from tkinter import messagebox


def test():
    cont = 0
    cont0 = 0
    cont1 = 1
    cont2 = 2
    while(TRUE):
        if(cont == -7):
            cont = 0
        # archivo 1
        f = open("../Bandas/Banda0.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont0)+","+str(cont))
        f.close()
        time.sleep(0.2)

        # archivo 1
        cont = random.randint(0,9)
        f = open("../Bandas/Banda1.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont1)+","+str(cont))
        f.close()
        time.sleep(0.5)

        # archivo 1
        cont = random.randint(0,9)
        f = open("../Bandas/Banda2.txt", "w")
        f.write("#tipo,posicion,\n"+str(cont2)+","+str(cont))
        f.close()
        time.sleep(1)
        cont -= 1

test()