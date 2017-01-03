#pragma once
#include "gc_file_system.h"

namespace gc
{
    class file_system_builder
    {
        path _root_path;
        shared_ptr<vector<hash_path>> _hash_paths;

    public:

        file_system_builder();
        file_system_builder(path& _root_path);
        file_system_builder(std::string _root_path);

        void set_root_path(boost::filesystem::path _root_path);

        shared_ptr<vector<hash_path>> hash_paths();

        void walk_directory();

        void walk_directory(boost::filesystem::path _root_path);


        ~file_system_builder();
    };
}
