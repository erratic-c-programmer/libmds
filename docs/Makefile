# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
all :
	doxygen Doxyfile
	sphinx-build -b html -Dbreathe_projects.libmds=xml/ . _build/
	sed -i 's/C++ class/C struct/' "_build/genindex.html"
	sed -i 's/C++/C/' "_build/genindex.html"
	sed -i 's/Public Members/Members/' "_build/index.html"

clean :
	rm -rf _build/*
