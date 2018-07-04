hw 3-1
利用fgets算出陣列的長與寬，然後將檔案指標重新指向一開始，再利用動態記憶體建立二維的迷宮(maze)跟走過路徑(mark)，再判斷起始點與終點，然後呼叫一個遞迴fnuction
，終止條件為找到'd'，如果未中止，則進入一個迴圈，並判斷是否能填入，如果可以，立起mark，然後進入遞迴的下一輪，如果有解，就將解的路徑寫入out.txt，當所有路徑都試過後
，如果沒有解，則no route!!，如果有一個以上的解，將印出所有的解，並顯示最短的步數。

hw 3-2 
noncircular queue

利用queue的定義，front/rear起始為-1，依序填入，當填滿時會顯示出Queue is full，並且不會填入，而當rear為maxsize-1，並且能填入數字，在填入數字時會向能填入的最左做位移，並將front定為-1，
如果在empty的情況下繼續刪除，則會將rear front回規-1。

circular queue

利用queue的定義，front/rear起始為0，當有數字被delete時，front向前位移一個，而如果能填入/刪除，並且rear/front為maxsize-1，填入/刪除的下一個為queue的開頭，當rear跟front的值一樣時則為empty。