## Part 1. Setting up the gitlab-runner

### == Task ==

#### Start Ubuntu Server 22.04 LTS virtual machine.

![Check version of Ubuntu](images/1.1.png)

#### Download and install gitlab-runner on the virtual machine.

Downloaded and installed gitlab-runner according to the instructions from the site:

[Installation instructions from the site](https://docs.gitlab.com/runner/install/linux-manually.html)


#### Run gitlab-runner and register it for use in the current project (DO6_CICD).

Running and register gitlab-runner according to the instructions from the site:

[Register instructions from the site](https://docs.gitlab.com/runner/register/index.html)


![Register gitlab-runner(1)](images/1.2.png)

Register gitlab-runner(1)

![Register gitlab-runner(2)](images/1.3.png)

Register gitlab-runner(2)

Start gitlab-runner:

![gitlab-runner start](images/1.4.png)

gitlab-runner start

## Part 2. Building

### == Task ==

#### Write a stage for CI to build applications from the C2_SimpleBashUtils project.

Create gitlab-ci.yml file:

![touch gitlab-ci.yml](images/2.1.png)

touch gitlab-ci.yml

Clone cat and grep utils files from out project C2 from gitlab:

![cat and grep utils](images/2.2.png)

cat and grep utils

##### In the gitlab-ci.yml file, add a stage to start the building via makefile from the C2 project.

##### Save post-build files (artifacts) to a random directory with a 30-day retention period.

![gitlab-ci.yml file contest](images/2.3.png)

gitlab-ci.yml file contest

#### Build testing in gitlab

##### Push our D06 directory to gitlab and test build:

![Build test](images/2.4.png)

Build test

## Part 3. Codestyle test

### == Task ==

#### Write a stage for CI that runs a codestyle script (clang-format).

![Added style stage to the .gitlab-ci.yml file](images/3.1.png)

Added style stage to the .gitlab-ci.yml file

![Script for clang-format style test](images/3.2.png)

Script for clang-format style test


#### If the codefile didn't pass, "fail" the pipeline.

#### In the pipeline, display the output of the clang-format utility.

![Failed style](images/3.3.png)

Failed style

![Failed style output](images/3.4.png)

Failed style output

And successful style pipeline:

![Successful style](images/3.5.png)

Successful style

![Successful style output](images/3.6.png)

Successful style output

## Part 4. Integration tests

### == Task ==

#### Write a stage for CI that runs your integration tests from the same project.

#### Run this stage automatically only if the build and codestyle test passes successfully.

![Added test stage to the .gitlab-ci.yml file](images/4.1.png)

Added test stage to the .gitlab-ci.yml file

![Script for integration tests](images/4.2.png)

Script for integration tests


#### If tests didn't pass, "fail" the pipeline.

![Failed tests](images/4.3.png)

Failed style

![Failed tests output](images/4.4.png)

Failed style output

If build and/or style stages failed then failed test stage too:

![Failed because build or style stage failed](images/4.5.png)

Failed because build or style stage failed

![Failed because build or style stage failed output](images/4.6.png)

Failed because build or style stage failed output


#### In the pipeline, display the output of the succeeded / failed integration tests.

![Success tests](images/4.7.png)

Success tests

![Success tests output](images/4.8.png)

Success tests output


## Part 5. Deployment stage

### == Task ==

#### Start the second virtual machine Ubuntu Server 22.04 LTS.

![Start second virtual machine](images/5.1.png)

Start second virtual machine

#### Local network betweem two virtual machines:

![Check network and 00-installer-config.yaml](images/5.2.png)

Check network and 00-installer-config.yaml

### Write a stage for CD that "deploys" the project on another virtual machine.

![Deploy stage in yaml](images/5.3.png)

Deploy stage in yaml


#### Write a bash script which copies the files received after the building (artifacts) into the /usr/local/bin directory of the second virtual machine using ssh and scp.

![Script for copying files](images/5.4.png)

Script for copying files

#### Proof that deploy stage has manually run:

![Manually run](images/5.5.png)

Manually run

#### Passed all stages

![All stages](images/5.6.png)

All stages

## Part 6. Bonus. Notifications

### == Task ==

#### Set up notifications of successful/unsuccessful pipeline execution via bot named "[your nickname] DO6 CI/CD" in Telegram.

![Some adds in .yml file](images/6.1.png)

Some adds in .yml file

#### Created new script for sending notification about pipeline execution

![Telegram notify script](images/6.2.png)

Telegram notify script


#### All pipeline stages successfully passed

![Successful stages](images/6.3.png)

Successful stages

#### After successful deploy_stage bot send to us message:

![Notify](images/6.4.png)

Notify

### == Task ==