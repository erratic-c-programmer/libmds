all : libmds doc

libmds : src/
	$(MAKE) -C $<

doc : docs/
	$(MAKE) -C $<
