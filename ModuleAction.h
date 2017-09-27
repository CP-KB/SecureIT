
class ModuleAction
{
    public:
        int Execute();

        std::string Name;
        std::string Description;
        std::vector<std::string> os;
        std::string ActionScript;
        std::string UnActionScript;

        std::vector<std::pair<std::string, std::string> > action_variable;
        std::vector<std::pair<std::string, std::string> > result_variable;
        std::string result;
}
