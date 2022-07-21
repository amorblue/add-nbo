TARGET=add-nbo
BE=echo
BE_INST= -n -e
a=thousand.bin
b=five-hundred.bin

main : $(TARGET) $(a) $(b)
	./$(TARGET) $(a) $(b)

$(TARGET) : $(TARGET).o
	gcc -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp
	gcc -c  $(TARGET).cpp

$(a):
	$(BE) $(BE_INST) \\x00\\x00\\x03\\xe8 > $(a) 
	
$(b):       
	$(BE) $(BE_INST) \\x00\\x00\\x01\\xf4 > $(b)


clean:
	rm -rf $(TARGET) $(TARGET).o $(a) $(b)


