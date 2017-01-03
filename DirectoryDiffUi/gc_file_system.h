#pragma once
#include <boost/filesystem/path.hpp>
#include "hash_path.h"
//#include "stdafx.h"

namespace gc
{
    using namespace std;
    using namespace boost::filesystem;

    class ifile_system_builder
    {
    public:
        virtual ~ifile_system_builder() = default;
        virtual void set_root_path(boost::filesystem::path _root_path);
        virtual void walk_directory();
        virtual void walk_directory(boost::filesystem::path _root_path);
        virtual shared_ptr<vector<hash_path>> hash_paths() const;
    };

    class idirectory_differ
    {
        shared_ptr<vector<hash_path>> execute();
    };

    class istaged_file
    {
        virtual void execute();
    };

    class ifile_copier
    {
        virtual void execute();
    };





    //struct file_system_builder : ifile_system_builder
    //{

    //	path _root_path;
    //	shared_ptr<vector<hash_path>> _hash_paths;

    //	file_system_builder(const path& _root_path)
    //		: _root_path(_root_path)
    //	{
    //		walk_directory();
    //	}

    //	void set_root_path(boost::filesystem::path _root_path) override
    //	{
    //		this->_root_path = _root_path;
    //	}

    //	shared_ptr<vector<hash_path>> hash_paths() const
    //	{
    //		return _hash_paths;
    //	}

    //	void walk_directory()
    //	{
    //		walk_directory(_root_path);
    //	}

    //	void walk_directory(boost::filesystem::path _root_path)
    //	{
    //		std::cout << "walk_directory(" << _root_path << ")" << std::endl;
    //		boost::filesystem::directory_iterator it = boost::filesystem::directory_iterator(_root_path), end;
    //		while (it != end)
    //		{
    //			if (boost::filesystem::is_regular_file(it->path()))
    //			{
    //				std::cout << "file found: " << it->path() << std::endl;
    //				_hash_paths->push_back(it->path());
    //			}
    //			else if (boost::filesystem::is_directory(it->path()))
    //			{
    //				this->walk_directory(it->path());
    //			}
    //			++it;
    //		}
    //	}
    //};

    struct directory_differ : idirectory_differ
    {
        shared_ptr<vector<hash_path>> _src_hash_paths;
        shared_ptr<vector<hash_path>> _dst_hash_paths;
        hash_cmp _hash_cmp;

        shared_ptr<vector<hash_path>> execute()
        {
            shared_ptr<vector<hash_path>> _diff = make_shared<vector<hash_path>>();
            std::set_difference(_src_hash_paths->begin(), _src_hash_paths->end(), _dst_hash_paths->begin(), _dst_hash_paths->end(),
                std::inserter(*_diff, _diff->begin()), hash_path::get_hash_digest_lt());
            return _diff;
        }
    };


    struct staged_file : istaged_file
    {
        path _src_path;
        path _dst_path;

        void execute()
        {
            assert(!exists(_dst_path));
            copy_file(_src_path, _dst_path);
        }
    };


    struct file_copier : ifile_copier
    {
        shared_ptr<vector<staged_file>> staged_files;

        void execute()
        {
            for_each(staged_files->begin(),staged_files->end(),[&](staged_file _staged_file)
            {
                _staged_file.execute();
            });
        }
    };
}

