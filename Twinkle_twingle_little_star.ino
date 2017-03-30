/*
  Separately excited buzzer (Playing Twinkle Twinkle Little Star)
*/
   const int buzzer = 2;			// Initialize location of the buzzer
   const int PB = A0;				// Initialize location of push button (LOW)
   int K=1, i, S;					// Declare push button variable, tone indicator, tone variable
   int voice[8]={523,587,698,784,880,932,988,1046};	// Initialize Tone Table array
   int Song[]={	1,1,5,5,  6,6,5,0,  4,4,3,3, 2,2,1,0,	// Initialize Tone array
   		5,5,4,4,  3,3,2,0,  5,5,4,4, 3,3,2,0, 100 };
   int Beat[]={	1,2,3,4,  2,2,3,4,  3,2,3,4, 4,2,3,4, 	// Initialize Beat array
   		1,2,3,4,  2,2,3,4,  3,2,3,4, 4,2,3,4 }; 
// Initial setup
   void setup() {                
   	pinMode(buzzer, OUTPUT);   
   }
// main
void loop() {
   K = digitalRead(PB); 		// Read push button
   if (!K) { 				// If PB is entered
   	i=0;
   	while (Song[i]!=100) {
   		if (Song[i]==0) 	// If mute
    			delay(Beat[i]*170);	// mute
   		else {
   			S=voice[(Song[i]-1)];	// Convert the scale frequency
   		        tone(buzzer, S);// play
                        delay(Beat[i]*170);
                        noTone(buzzer);
   		} 
   		i++;		// next
   	}
   }
}

