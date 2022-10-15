## Using Ansible and Packer, From Provisioning to Orchestration

Ansible Automation Platform can help you orchestrate, operationalize and govern your hybrid cloud deployments.  In my last public cloud blog, I talked about Two Simple Ways Automation Can Save You Money on Your AWS Bill and similarly to Ashton’s blog Bringing Order to the Cloud: Day 2 Operations in AWS with Ansible, we both wanted to look outside the common public cloud use-case of provisioning and deprovisioning resources and instead look at automating common operational tasks.  For this blog post I want to cover how the Technical Marketing team for Ansible orchestrates a pipeline for demos and workshops with Ansible and how we integrate that with custom AMIs (Amazon Machine Images) created with Packer.  Packer is an open source tool that allows IT operators to standardize and automate the process of building system images.

For some of our self-paced interactive hands-on labs on Ansible.com, we can quickly spin up images in seconds.  In an example automation pipeline we will:

Provision a virtual instance.
Use Ansible Automation Platform to install an application; in my case, I am literally installing our product Ansible Automation Platform (is that too meta?).
After the application install, set up the lab guides, pre-load automation controller with some job templates, create inventory and credentials and even set up SSL certificates.  
While this is fast, it might take a few minutes to load, and web users are unlikely to be patient.  The Netflix era means that people want instant gratification!  Installing automation controller might take five to 10 minutes, so I need a faster method to deploy.
