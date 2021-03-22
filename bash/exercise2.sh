####################################################################################################################
#       __  ___      ___  _______   _______        __       _______    _______   _______   
#      /""\|"  \    /"  |/"     "| /"      \      /""\     /" _   "|  /"     "| /"      \  
#     /    \\   \  //  /(: ______)|:        |    /    \   (: ( \___) (: ______)|:        | 
#    /' /\  \\\  \/. ./  \/    |  |_____/   )   /' /\  \   \/ \       \/    |  |_____/   ) 
#   //  __'  \\.    //   // ___)_  //      /   //  __'  \  //  \ ___  // ___)_  //      /  
#  /   /  \\  \\\   /   (:      "||:  __   \  /   /  \\  \(:   _(  _|(:      "||:  __   \  
# (___/    \___)\__/     \_______)|__|  \___)(___/    \___)\_______)  \_______)|__|  \___) 
#                                                                                          
# Create a shell script able to accept as an input a file with one number per line and return their average.
# It must support an arbitrary file length.
#
# Bonus: in case the lines are CSV (comma-separed values) treat each column as a different file, returning the 
#        averages as a single CSV line.
# 
####################################################################################################################
SUM=0
NUM_OF_ELEMENT=0
for data in $(cat $1);
do
SUM=$(($SUM+$data))
NUM_OF_ELEMENT=$(($NUM_OF_ELEMENT+1))
done
echo $SUM
echo $NUM_OF_ELEMENT
echo "scale=2; $SUM/$NUM_OF_ELEMENT" | bc

