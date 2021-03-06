#!/bin/bash
#
# Check geovector symbols

ps=geovector.ps

# Vector from point with head at end
cat << EOF > t.txt
-40 30 0 60 19000
0 -30 0 20 13000
EOF
gmt psxyz -R-180/180/-75/75 -JM6i -Bag -W0.5p,red -S=0.4i+jb+e+r+h1 -P -Gred t.txt -K -p155/35 > $ps
gmt psxyz -R -J -O -K -Sc0.05i -Gred t.txt -p155/35 >> $ps
# Centered double-head vector
cat << EOF > t.txt
-120 0 0 45 10000
60 -50 0 20 6000
EOF
gmt psxyz -R -J -W0.5p,blue -S=0.4i+jc+b+e+h1 -Gblue t.txt -O -K -p155/35 >> $ps
gmt psxyz -R -J -Sc0.05i -Gblue t.txt -O -K -p155/35 >> $ps
# Vector to point with head at start
cat << EOF > t.txt
-60 10 0 5 8000
-140 -65 0 80 6000
EOF
gmt psxyz -R -J -W0.5p,black -S=0.4i+je+e+a20+l+h1 t.txt -O -K -p155/35 >> $ps
gmt psxyz -R -J -Sc0.05i -Gblack t.txt -O -p155/35 >> $ps
