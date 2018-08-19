#ifndef MENUS_H
#define MENUS_H


class menus
{
    public:
        menus();
        void menu_selector(int opt);
        void main_menu();
        void level_menu();
        void restart();

    protected:

    private:
        int pointer;
};

#endif // MENUS_H
