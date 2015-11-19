GRAPH_FILE = graph.txt
NPARTS = 3
OUTPUT = graph.txt.part.$(NPARTS)

$(OUTPUT): $(GRAPH_FILE)
	gpmetis $(GRAPH_FILE) $(NPARTS)

clean: 
	rm -f $(OUTPUT)	
