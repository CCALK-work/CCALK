import sys

if (len(sys.argv) < 2) :
    sys.exit("Trace path needed")

#Parameters to change
nLignes = 2048                  #number of line of trace file
pathFileTrace = sys.argv[1]   #trace path
keylengh = 128                  #key lengh to retrieve
shift = 200                     #shit to apply to the trace to start analysis on an entire pattern
motif_width = 256               #equal to number of cache lignes / associativity (or number of sets)

#AES key in bit
keyVerif = "11010100011111101010100001101000000101000111010101001011011001011101010111101111101010000001000110010000111100111111001000111100"

#function to retrieve number of cache miss for each array index
def recupValueOneTrace(line, oneTrace) :
    oneTrace.append(int([char for char in line.split(' ')][2]))

def retrieveKey() :
        oneTrace = []
        values = [0] * motif_width
        nameFile = pathFileTrace + "/mesure" + ".txt"
        file = open(nameFile, "r")
        lines = file.readlines()
        file.close()

        #retrieve values
        for line in lines :
            recupValueOneTrace(line, oneTrace)
        
        #create pattern values as the average of all patterns
        for i in range (nLignes-shift) :
            values[i%motif_width] += oneTrace[i+shift]

        print(values)

        #compute threshold
        threshold = (max(values) + min(values)) /2
        print("\nTHRESHOLD DEFINITION : ")
        print("THRESHOLD : ", threshold)

        counter = 0
        keyRetrieve = []
        #skip beginning of the trace  
        while(values[counter] < threshold):
            counter = counter + 1
            continue

        #beginning of pattern
        for i in range (keylengh):
            keyRetrieve.append(values[counter] > threshold)
            counter = counter +1

        print("\n DATA RETRIEVE : ")

        counterValueCorrect = 0
        for i in range (keylengh) :
            if(int(keyVerif[i]) == (int(keyRetrieve[i]))) :
                counterValueCorrect = counterValueCorrect + 1 
            print(int(keyVerif[i]) == (int(keyRetrieve[i])))
        print("Success rate : ", counterValueCorrect/keylengh)
        return counterValueCorrect/keylengh

retrieveKey()