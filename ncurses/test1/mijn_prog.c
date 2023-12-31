#include "cdk.h"

#ifdef HAVE_XCURSES
char *XCursesProgramName="Mijn_Prog";
#endif

int main (int argc, char **argv)
{
   /* Declare variables. */
   CDKSCREEN *cdkscreen	= (CDKSCREEN *)NULL;
   CDKDIALOG *question	= (CDKDIALOG *)NULL;
   WINDOW *cursesWin	= (WINDOW *)NULL;
   char *buttons[]	= {"</B/24>Ok", "</B16>Cancel"};
   char *message[10], *mesg[10], temp[100];
   int selection;

   /* Set up CDK. */
   cursesWin = initscr();
   cdkscreen = initCDKScreen (cursesWin);

   /* Start color. */
   initCDKColor();

   /* Create the message within the dialog box. */
   message[0]	= "<C></U>Dialog Widget Demo";
   message[1]	= " ";
   message[2]	= "<C>The dialog widget allows the programmer to create";
   message[3]	= "<C>a popup dialog box with buttons. The dialog box";
   message[4]	= "<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>";
   message[5]	= "<R>and even be justified.";
   message[6]	= "<C>Even the buttons can have colours.";

   /* Create the dialog box. */
   question = newCDKDialog (cdkscreen, CENTER, CENTER,
				message, 7, buttons, 2,
				COLOR_PAIR(2)|A_REVERSE,
				TRUE, TRUE, FALSE);

   /* Check if we got a null value back. */
   if (question == (CDKDIALOG *)NULL)
   {
      /* Shut down Cdk. */
      destroyCDKScreen (cdkscreen);
      endCDK();

      /* Spit out a message. */
      printf ("Oops. Can't seem to create the dialog box. Is the window too small?\n");
      exit (1);
   }

   /* Activate the dialog box. */
   selection = activateCDKDialog (question, (chtype *)NULL);

   /* Tell them what was selected. */
   if (question->exitType == vESCAPE_HIT)
   {
      mesg[0] = "<C>You hit escape. No button selected.";
      mesg[1] = "",
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 3);
   }
   else if (question->exitType == vNORMAL)
   {
      sprintf (temp, "<C>You selected button #%d", selection);
      mesg[0] = copyChar (temp);
      mesg[1] = "";
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 3);
   }

   /* Clean up. */
   destroyCDKDialog (question);
   destroyCDKScreen (cdkscreen);
   endCDK();
   delwin (cursesWin);
   exit (0);
}
