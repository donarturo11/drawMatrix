#ifndef TEXTUI_H 
#define TEXTUI_H


#include <iostream>
#include <map>
#include "DrawMatrix.h"
#include "FencePicture.h"

class TextUI {
  public:
      TextUI();
      ~TextUI();
      void runCommand(std::string command);
                  
   private:
      void greateUser();
      void run();
      void helpCmd();
      void wrongCmd();
      void startCmd();
      void stopCmd();
      void setGeometryCmd();
      void clearCmd();
      void displayCmd();
      void displayRawCmd();
      void assignCmd();
      void moveCmd();
      void rmoveCmd();
      void fillCmd();
      void drawCmd();
      void drawLineCmd();
      void refreshCmd();
      void dimensionsCmd();
      void positionCmd();
      void drawFenceCmd();
      void printText(std::string text);
      
      
      
    protected:  
      
      DrawMatrix * picture;
      FencePicture * fence;
    
};

#endif
