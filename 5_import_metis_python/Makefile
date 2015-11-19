example.svg: example.dot
	dot -Tsvg $< > $@

example.dot: main.py
	python $<

clean:
	rm -f example.dot example.svg
