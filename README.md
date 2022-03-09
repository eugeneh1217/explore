# explore
Monorepo containing my projects from 2022 onwards
# makefile commands
* `make create-proj PROJ=project_path`
    * arguments
        * `PROJ`: project folder path
    * behavior:
        * create project called `project_path`
        * creates `project_path` directory if it does not exist
* `make add-cpp PROJ=project_path`
    * set up environment to write, build, and test c++ code in `project_path`
    * behavior:
        * makes `test`, `build` and `src` directories in `project_path`
        * copies cpp makefile from `tooling` directory into `project_path`
