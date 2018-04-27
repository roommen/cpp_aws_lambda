ROOT := .

include $(ROOT)/make-include.mk

SRCS = encDec.cpp mainEncDec.cpp
CUST_ENC_DEC = customerEncDec

all: install

install:
	$(GPP) $(GPP_FLAGS) $(SRCS) -o $(CUST_ENC_DEC)

clean:
	rm -f $(CUST_ENC_DEC)
	rm -f passphrase.h
