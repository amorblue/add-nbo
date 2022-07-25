TARGET=add-nbo

main : $(TARGET)
	./$(TARGET) thousand.bin five-hundred.bin

$(TARGET) : $(TARGET).o
	gcc -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp
	gcc -c  $(TARGET).cpp

clean:
	rm -rf $(TARGET)
	rm -rf $(TARGET).o


