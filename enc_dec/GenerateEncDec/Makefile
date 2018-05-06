ROOT := .

include $(ROOT)/make-include.mk

SRCS = genPassPhrase.cpp sha256.cpp mainPassPhrase.cpp
GEN_PP = genPP

all: install

install:
	$(GPP) $(GPP_FLAGS) $(SRCS) -o $(GEN_PP) $(LDFLAGS)

clean:
	rm -f $(GEN_PP)
	rm -f passphrase.h
