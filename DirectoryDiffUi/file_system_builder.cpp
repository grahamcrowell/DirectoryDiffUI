#include "stdafx.h"
#include "file_system_builder.h"



gc::file_system_builder::file_system_builder()
{
    _hash_paths = std::make_shared<std::vector<gc::hash_path>>();
}

gc::file_system_builder::file_system_builder(boost::filesystem::path& _root_path)
{
    this->_root_path = _root_path;
    _hash_paths = std::make_shared<std::vector<gc::hash_path>>();
    walk_directory();
}

gc::file_system_builder::file_system_builder(std::string _root_path)
{
    _hash_paths = std::make_shared<std::vector<gc::hash_path>>();
    this->_root_path = path(_root_path);
}

void gc::file_system_builder::set_root_path(boost::filesystem::path _root_path)
{
    this->_root_path = _root_path;
}

std::shared_ptr<std::vector<gc::hash_path>> gc::file_system_builder::hash_paths()
{
    return _hash_paths;
}

void gc::file_system_builder::walk_directory()
{
    walk_directory(_root_path);
}

void gc::file_system_builder::walk_directory(boost::filesystem::path _root_path)
{
    std::cout << "walk_directory(" << _root_path << ")" << std::endl;
    boost::filesystem::directory_iterator it = boost::filesystem::directory_iterator(_root_path), end;
    while (it != end)
    {
        if (boost::filesystem::is_regular_file(it->path()))
        {
            std::cout << "file found: " << it->path() << std::endl;
            _hash_paths->push_back(it->path());

            std::cout << "file pushed: " << it->path() << std::endl;
        }
        else if (boost::filesystem::is_directory(it->path()))
        {
            this->walk_directory(it->path());
        }
        ++it;
    }
}


gc::file_system_builder::~file_system_builder()
{
}
