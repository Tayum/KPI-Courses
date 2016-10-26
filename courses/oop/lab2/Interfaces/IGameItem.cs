namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    interface IGameItem
    {
        string Name { get; set; }

        void calculateEfficiency();

        void increaseDurability(int value);
        void decreaseDurability(int value);
    }
}
