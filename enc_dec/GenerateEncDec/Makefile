ROOT := .

include $(ROOT)/make-include.mk

GENPP_SRCS = GeneratePassPhrase.cpp SHA256.cpp MainGeneratePassPhrase.cpp
GENPP = genPP
CUSTENC_SRCS = CustomerEncrypt.cpp MainCustomerEncrypt.cpp
CUSTENC = custEnc

all: $(GENPP)

$(GENPP):
	$(GCC) $(GCC_FLAGS) $(GENPP_SRCS) -o $(GENPP) $(LDFLAGS)

$(CUSTENC):
	$(GCC) $(GCC_FLAGS) $(CUSTENC_SRCS) -o $(CUSTENC)

clean:
	rm -f $(GENPP)
	rm -f $(CUSTENC)
	rm -f passphrase.h
