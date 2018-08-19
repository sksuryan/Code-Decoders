#ifndef GAMEPLAY_H
#define GAMEPLAY_H


class gameplay
{
    public:
        gameplay();
        void gameplay_chooser(int a);
        void gameplay_easy();
        void gameplay_hard();
        void check_easy(int random[], int choosen[4]);
        void check_hard(int random[], int choosen[5]);
        void youwin();

    protected:

    private:
        int random[6];
        int choosen[5];

        int i;
};

#endif // GAMEPLAY_H
