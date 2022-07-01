import sys
import matplotlib.pyplot as plt

if (len(sys.argv) < 2) :
    sys.exit("Trace path needed")

#Parameters to change
nLines = 2048                   #number of line of trace file
pathFileTrace = sys.argv[1]     #trace path
nTrace = 1                      #number of trace

#function to retrieve number of cache miss for each array index
def recupValueOneTrace(line, oneTrace) :
    oneTrace.append(int([char for char in line.split(' ')][2]))

#function to graph trace 
def graphe() :
    oneTrace = []
    nameFile = pathFileTrace + "/mesure" + ".txt"
    file = open(nameFile, "r")
    lines = file.readlines()
    file.close()
    for line in lines :
        recupValueOneTrace(line, oneTrace)

    #ordinate axis 
    y = []
    for i in range (nLines) :
        y.append(i)

    #abscissa axis
    counter = 0
    for j in range (nTrace):
        bitonebyone = oneTrace[counter*nLines:(counter+1)*nLines]
        counter = counter + 1

        plt.plot(y, bitonebyone) 
        plt.xlabel("Array index")
        plt.ylabel("Number of cache miss") 
        plt.title(sys.argv[1])
        plt.show()
        plt.close()

graphe()