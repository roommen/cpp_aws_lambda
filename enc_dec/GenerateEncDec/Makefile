ROOT := .

include $(ROOT)/make-include.mk

GENPP_SRCS = GeneratePassPhrase.cpp SHA256.cpp MainGeneratePassPhrase.cpp
GENPP = genPP
CUSTENCDEC_SRCS = CustomerEncryptDecrypt.cpp MainCustomerEncryptDecrypt.cpp
CUSTENCDEC = custEncDec

all: $(GENPP)

$(GENPP):
	$(GCC) $(GCC_FLAGS) $(GENPP_SRCS) -o $(GENPP) $(LDFLAGS)

$(CUSTENCDEC):
	$(GCC) $(GCC_FLAGS) $(CUSTENCDEC_SRCS) -o $(CUSTENCDEC)

clean:
	rm -f $(GENPP)
	rm -f $(CUSTENCDEC)
	rm -f passphrase.h
