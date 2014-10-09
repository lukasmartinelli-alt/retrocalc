LIB = retrocalclib/Debug
TEST = retrocalclibtest/Debug

MY_TARGETS = $(LIB) $(TEST)

.PHONY: all $(MY_TARGETS)
	all: $(MY_TARGETS)

$(MY_TARGETS):
	@$(MAKE) -C $@;

$(TEST): $(LIB)

