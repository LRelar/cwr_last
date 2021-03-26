rm -rf corFiles/*/*.cor
rm -rf corFiles/*/*.log
rm -rf result
date="$(date)"
for i in $(find champs -maxdepth 1 -name  *.s); 
 do 
	
	./asm $i >> corFiles/our/run$date.log
	f="$(basename -s .s $i)"
	echo "$f"
	
	chmod 777 champs/$f.cor 
	mv champs/*.cor corFiles/our
	./asm-school $i >> corFiles/school/run$date.log
	chmod 777 champs/$f.cor 
	mv champs/*.cor corFiles/school
	diff corFiles/our/$f.cor corFiles/school/$f.cor >> result
 done
