# MES ALIAS

   
````
alias  -g  cc_this="cc -Wall -Wextra -Werror"
alias  -g  norme_me="echo 'yes sir !\n'; norminette -R CheckForbiddenSourceHeader"
alias  aled="echo '\n\t\t\t\t\t\t\t---------------------------------------------------------------------------\n\t\t\t\t\t\t\t ~The feeling of your socks squishing as you step gives you determination~ \n\t\t\t\t\t\t\t---------------------------------------------------------------------------\n'";
alias  cl="clear; echo '\naww~ look at u all cleaned up :*'"

push_it  ()
{
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\t Hello cutie :* let me push it for ya <3\n\t\t\t\t\t\t\t ok let's check the status first do we ? :)\n\t\t\t\t\t\t\t--------------------------------------------\n\n";
git status;
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\t\t\t nice :D\n\t\t\t\t\t\t\t\tnow we add all of those shit...\n\t\t\t\t\t\t\t--------------------------------------------\n\n";
git add  *;
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\t\t\t yay :D\n\t\t\t\t\t\t\t\t let's check again~\n\t\t\t\t\t\t\t--------------------------------------------\n\n";
git status;
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\tOh u've found one cute name already right ?\n\t\t\t\t\t\t\t\t then let's create it ^^\n\t\t\t\t\t\t\t--------------------------------------------\n\n";
git commit  -m  $1;
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\t\t we're almost done :D\n\t\t\t\t\t\t\t\t\tok last move\n\t\t\t\t\t\t\t--------------------------------------------\n\n";
git push;
echo  "\n\t\t\t\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t\t Everything's sent to the magic clouud~\n\t\t\t\t\t\t\t\twell done baby see ya soon ! <3\n\t\t\t\t\t\t\t--------------------------------------------\n\n\n"
}
````