#include <filesystem>
#include <game.hpp>


int main(int argc, char** argv)
{
    std::string path(argv[0]);
    path = path.substr(0, path.find_last_of('\\') + 1);
    std::filesystem::current_path(path);
    Game::instance().run();

    return 0;
}
