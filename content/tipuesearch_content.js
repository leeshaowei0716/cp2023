var tipuesearch = {"pages": [{'title': '關於', 'text': 'https://github.com/mdecycu/cmsite \n', 'tags': '', 'url': '關於.html'}, {'title': 'w6', 'text': '// https://en.wikipedia.org/wiki/Flag_of_thcp2023.a0968899313.repl.coe_Republic_of_China  // cc roc_flag.c -lgd -lm 連接gd與數學庫 // https://www.rapidtables.com/ web/ color/RGB_Color.html  // 幾何形狀著色與繪圖練習 //以下gd繪畫教學嘗試類似的中華民國國旗，請根據以下計劃內容完成後續的國旗綁定 #include <stdio.h>  #include <gd.h >  #包括 <math.h> \n voiddraw_roc_flag（gdImagePtr img）； void draw_white_sun(gdImagePtr img, int x, int y, int size, int color); \n int main() {  // 寬度 3: 高度 2  int width = 1200;  int 高度 = (int)(寬度*2.0 / 3.0); \n gdImagePtr img = gdImageCreateTrueColor(寬度, 高度);  gdImageAlphaBlending(img, 0); \n 鄰近_roc_flag（img）； \n FILE *outputFile = fopen("./../images/roc_flag.png", "wb");  if (outputFile == NULL) {  fprintf(stderr, "開啟輸出檔時發生錯誤。\\n"); 回傳1； gdImagePngEx  (img, 輸出檔, 9);  fclose(輸出檔);  gdImageDestroy(img); 回傳0； } \n drawroVinc_flag（gdImagePtr img）{  int寬度= gdImageSX（img）;  int 高度 = gdImageSY(img);  int 紅、白、藍； int center_x = (int)(寬度/4);  int center_y = (int)(高度/4);  int sun_radius = (int)(寬度/8);  // 標誌的顏色 red = gdImageColorAllocate(img, 242, 0, 0);  // 紅白 = gdImageColorAllocate(img, 255, 255, 255);  // 白色條紋 藍色 = gdImageColorAllocate(img, 0, 41, 204);  // 藍色 // 紅色自訂區域 gdImageFilledRectangle(img, 0, 0, width, height, red);  // 藍色區域 gdImageFilledRectangle(img, 0, 0, (int)(width/2.0), (int)(height/2.0), blue);  // 目前只出青天白日的直線，請嘗試計算所需的點座標完成國旗繪圖 draw_white_sun(img, center_x, center_y, sun_radius, White);  } \n void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) { 浮動角度 = 0;  int fromX, fromY;  int toX, toY;  for (int i=0; i<24; i++){ 角度 += 5*M_PI*2/12;  //printf("%.3f", 角度);  toX = center_x + cos(角度)*sun_radius;  toY = center_y + sin(角度)*sun_radius;  // 允許 i 為 0 時移動到 toX, toY，其餘都進行直線不平等 if (i!=0){  gdImageLine(img, fromX, fromY, toX, toY, color);  } 從X = 到X; 從Y = 到Y;  }  } \n \n \n \n // https://en.wikipedia.org/wiki/Flag_of_thcp2023.a0968899313.repl.coe_Republic_of_China  // cc roc_flag.c -lgd -lm 連接gd與數學庫 // https://www.rapidtables.com/ web/ color/RGB_Color.html  // 幾何形狀著色與繪圖練習 //以下gd繪畫教學嘗試類似的中華民國國旗，請根據以下計劃內容完成後續的國旗綁定 #include <stdio.h>  #include <gd.h >  #包括 <math.h> \n voiddraw_roc_flag（gdImagePtr img）； void draw_white_sun(gdImagePtr img, int x, int y, int size, int color); \n int main() {  // 寬度 3: 高度 2  int width = 1200;  int 高度 = (int)(寬度*2.0 / 3.0); \n gdImagePtr img = gdImageCreateTrueColor(寬度, 高度);  gdImageAlphaBlending(img, 0); \n 鄰近_roc_flag（img）； \n FILE *outputFile = fopen("./../images/roc_flag.png", "wb");  if (outputFile == NULL) {  fprintf(stderr, "開啟輸出檔時發生錯誤。\\n"); 回傳1； gdImagePngEx  (img, 輸出檔, 9);  fclose(輸出檔);  gdImageDestroy(img); 回傳0； } \n drawroVinc_flag（gdImagePtr img）{  int寬度= gdImageSX（img）;  int 高度 = gdImageSY(img);  int 紅、白、藍； int center_x = (int)(寬度/4);  int center_y = (int)(高度/4);  int sun_radius = (int)(寬度/8);  // 標誌的顏色 red = gdImageColorAllocate(img, 242, 0, 0);  // 紅白 = gdImageColorAllocate(img, 255, 255, 255);  // 白色條紋 藍色 = gdImageColorAllocate(img, 0, 41, 204);  // 藍色 // 紅色自訂區域 gdImageFilledRectangle(img, 0, 0, width, height, red);  // 藍色區域 gdImageFilledRectangle(img, 0, 0, (int)(width/2.0), (int)(height/2.0), blue);  // 目前只出青天白日的直線，請嘗試計算所需的點座標完成國旗繪圖 draw_white_sun(img, center_x, center_y, sun_radius, White);  } \n void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) { 浮動角度 = 0;  int fromX, fromY;  int toX, toY;  for (int i=0; i<24; i++){ 角度 += 5*M_PI*2/12;  //printf("%.3f", 角度);  toX = center_x + cos(角度)*sun_radius;  toY = center_y + sin(角度)*sun_radius;  // 允許 i 為 0 時移動到 toX, toY，其餘都進行直線不平等 if (i!=0){  gdImageLine(img, fromX, fromY, toX, toY, color);  } 從X = 到X; 從Y = 到Y;  }  } \n \n \n // 包含標準輸出入程式庫的標頭檔 // https://blog.csdn.net/weixin_38468077/article/details/101069365  // http://www.gnuplot.info/demo/  // https:/ /https:// /https:///github.com/sysprog21/rv32emu  // https://github.com/sysprog21/semu  // https://docs.google.com/presentation/d/14N0cWG2SnBSqhc2cLF0_2VerB9FF8JN3  // https://cs61c .org/fa23/  // https://greenteapress.com/wp/think-python-2e/  // https://github.com/ecalvadi/c99-examples  // https://github .com/gouravthakur39/初學者-C-program -examples  // https://github.com/ergenekonyigit/Numerical-Analysis-Examples  // https://www.che.ncku.edu.tw/facultyweb/changct/ html/teaching/CPPandMATLAB/ Past/pdf%20Files /Chap02-Ling.pdf  // https://gteceducation.com.sg/Brochures/PROGRAMMING/C%20PROGRAMMING%20FULL.pdf  // https://jsommers.github. io/cbook/cbook。 pdf  // https://jsomers.github.io/cbook/index.html  // http://student.itee.uq.edu.au/courses/csse2310/CProgrammingNotes.pdf  // http://cslibrary.stanford .edu/101/ EssentialC.pdf  // https://publications.gbdirect.co.uk/c_book/  // https://www.fossil-scm.org/fossil-book/doc/2ndEdition/fossilbook.pdf  / / **** * 在replit 執行 // cd 下載 // cc gnuplot_ex1.c -o gnuplot_ex1  // ./gnuplot_ex1  #include <stdio.h> \n // 主函式 int main() {  //popen 啟動 Gnuplot 程式 FILE *gnuplotPipe = popen("gnuplot -persistent", "w");  if (!gnuplotPipe) {  fprintf(stderr, "啟動Gnuplot失敗。\\n"); 回傳1； } \n // 使用 Gnuplot 繪圖指令，指定字體並輸出為 PNG  fprintf(gnuplotPipe, "setterminal png font \'default,10\' size 800,400\\n");  fprintf(gnuplotPipe, "設定輸出 \'./../images/gnuplot_ex1.png\'\\n");  fprintf(gnuplotPipe, "強度 sin(x)");  // 關閉 popen  pclose(gnuplotPipe); \n 返回0； } \n #include <stdio.h>  #include <gd.h>  #include <math.h> \n int main() {  int 寬度 = 800;  整數高度=600； \n gdImagePtr img = gdImageCreateTrueColor(寬度, 高度);  gdImageAlphaBlending(img, 0); \n FILE *outputFile = fopen("hellogd.png", "wb");  如果（輸出檔== NULL）{ \n fprintf(stderr, "開啟輸出檔時發生錯誤。\\n"); \n 返回1； } \n int 紅色 = gdImageColorAllocate(img, 255, 0, 0);  int 藍色 = gdImageColorAllocate(img, 0, 0, 255);  int black = gdImageColorAllocate(img, 0, 0, 0);  int 白色 = gdImageColorAllocate(img, 255, 255, 255);  // 長方形塗色 gdImageFilledRectangle(img, 0, 0, width, height, white);  gdImageFilledRectangle(img, 0, 0, (int)width/4, (int)height/4, 藍色);  // 橢圓形著色 gdImageFilledEllipse(img, (int)width*3/4, (int)height/4, (int)width/4, (int)width/4, red);  // 圓形畫線 gdImageEllipse(img, (int)width*3/4, (int)height*3/4, (int)width/4, (int)width/4, red);  // 畫直線 gdImageLine(img, (int)width/2, (int)height/2, (int)width/2, (int)height/2 + 100, blue); \n // 施工畫線 gdPoint points[4];  點[0].x = (int)寬度/4;  點[0].y = (int)高度*3/4;  點[1].x = 點[0].x + 100； 點[1].y = 點[0].y;  點[2].x = 點[1].x； 點[2].y = 點[1].y + 100； 點[3].x = 點[2].x - 100； 點[3].y = 點[2].y;  gdImagePolygon(img, 點, 4, 黑色); \n // 廈門著色 gdPointpoints2[4];  點2[0].x = (int)寬度/3;  點2[0].y = (int)高度/2;  點2[1].x = 點2[0].x + 100； 點2[1].y = 點2[0].y;  點2[2].x = 點2[1].x;  點2[2].y = 點2[1].y + 100； 點2[3].x = 點2[2].x - 150； 點2[3].y = 點2[2].y;  gdImageFilledPolygon(img, 點2, 4, 紅色); \n gdImagePngEx(img, 輸出檔, 9);  fclose(輸出檔);  gdImageDestroy(img);  返回0； } \n', 'tags': '', 'url': 'w6.html'}, {'title': 'W11', 'text': '#include <stdio.h> #include <gd.h> #include <stdlib.h> \n void drawJapaneseFlag() {  int width = 300; // 寬度  int height = 200; // 高度  int radius = 50; // 圓圈半徑  int centerX = 150; // 圓圈中心X座標  int centerY = 100; // 圓圈中心Y座標 \n // 創建一個 24 位的彩色圖片  gdImagePtr im = gdImageCreateTrueColor(width, height); \n // 設置背景色為白色  int white = gdImageColorAllocate(im, 255, 255, 255);  gdImageFill(im, 0, 0, white); \n // 設置圓圈的顏色為紅色  int red = gdImageColorAllocate(im, 255, 0, 0); \n // 畫紅色圓圈  gdImageFilledEllipse(im, centerX, centerY, 2 * radius, 2 * radius, red); \n // 輸出圖片到檔案  FILE *output = fopen("japanese_flag.png", "wb");  if (output == NULL) {  fprintf(stderr, "Unable to open file for writing.\\n");  exit(EXIT_FAILURE);  } \n gdImagePng(im, output); \n // 釋放內存  gdImageDestroy(im);  fclose(output); } \n int main() {  drawJapaneseFlag();  printf("Japanese flag created: japanese_flag.png\\n");  return 0; } \n \n', 'tags': '', 'url': 'W11.html'}, {'title': '布萊頓', 'text': 'https://en.wikipedia.org/wiki/Python_（程式語言） \n 例子： \n https://gist.github.com/mdecycu/d9082d678096bd58378d6afe2c7fa05d \n https://www.geeksforgeeks.org/python-programming-examples/ \n https://www.programiz.com/python-programming/examples \n https://www.freecodecamp.org/news/python-code-examples-sample-script-coding-tutorial-for-beginners/ \n Python教學： \n https://docs.python.org/3/tutorial/ \n Python的平衡介紹 \n 縮排（Python採用4個Spaces縮排，以介面執行範圍） \n 變數（ Python 關鍵字 ） \n 註（#單行註解、三單標註或三雙標註標註多行註解） \n 數 (整數 int(), 浮點數 float()) \n 字串 （字符串） \n print (Python 內建函數,  print() 函數式) \n Python是控制流程工具 \n 為了 \n 如果 \n 範圍 \n 開放 \n 讀 \n 清單 \n 元組 \n 字典 \n 功能 \n 嘗試...除了 \n 休息時間 \n 曾經 \n 類別 \n 此頁面示範如何在同一頁面下加入多個線上Ace編輯器與執行按鈕（ practice_html.txt 動態頁面超檔案）。 \n Practice_html.txt 動態頁面超檔案應該可以在啟動Brython時，設定分割.py檔案放入downloads/py目錄中引用。 \n 也所有即將出現的對應 html 也使用 Brython 產生，然後編寫為 類別 後，在範例匯入時交叉 實例 引用。 \n <!-- 啟動 Brython --> \n<腳本> \n視窗.onload=函數(){ \nbrython({debug:1, pythonpath:[\'./../cmsimde/static/\',\'./../downloads/py/\']}); \n} \n</> 腳本 \n 從1累加到100： \n 1加到100 \n 將 iterable 與 iterator 相關說明 ，利用 Brython 與 Ace Editor 整理頁面。 \n  導入 brython 程式庫  \n \n \n \n \n  啟動 Brython  \n \n \n \n  導入 FileSaver 與 filereader  \n \n \n \n \n  導入 ace  \n \n \n \n \n \n \n  導入 gearUtils-0.9.js Cango 齒輪繪圖程式庫  \n \n \n \n \n \n \n  請注意, 這裡使用 Javascript 將 localStorage["kw_py_src1"] 中存在近端瀏覽器的程式碼, 由使用者決定存檔名稱 \n \n \n \n \n \n \n  add 1 to 100 開始  \n \n \n  add 1 to 100 結束 \n  editor1 開始  \n  用來顯示程式碼的 editor 區域  \n \n  以下的表單與按鈕與前面的 Javascript doSave 函式以及 FileSaver.min.js 互相配合  \n  存擋表單開始  \n 文件名稱： .py   \n  存擋表單結束  \n \n  執行與清除按鈕開始  \n 跑步   輸出   明確輸出區 清晰的繪圖區 重新載入 \n  執行與清除按鈕結束  \n \n  程式執行 ouput 區  \n \n  Brython 程式執行的結果, 都以 brython_div1 作為切入位置  \n \n  editor1 結束   ##########################################  \n 從1累加到100第2部分： \n 1加到100 cango_三_齒輪 BS蛇 人工智慧俄羅斯區塊鏈 旋轉塊 \n  請注意, 這裡使用 Javascript 將 localStorage["kw_py_src2"] 中存在近端瀏覽器的程式碼, 由使用者決定存檔名稱 \n \n \n \n  add 1 to 100 part2 開始  \n \n \n  add 1 to 100 part2 結束 \n  editor2 開始  \n  用來顯示程式碼的 editor 區域  \n \n  以下的表單與按鈕與前面的 Javascript doSave 函式以及 FileSaver.min.js 互相配合  \n  存擋表單開始  \n 文件名稱： .py   \n  存擋表單結束  \n \n  執行與清除按鈕開始  \n 跑步   輸出   明確輸出區 清晰的繪圖區 重新載入 \n  執行與清除按鈕結束  \n \n  程式執行 ouput 區  \n \n  Brython 程式執行的結果, 都以 brython_div1 作為切入位置  \n \n  editor2 結束  \n \n \n', 'tags': '', 'url': '布萊頓.html'}]};