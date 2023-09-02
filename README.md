# fn-curl: Fortnite Launcher Redirect DLL

![Project Logo](Logo.png) <!-- If you have a logo, place it in the repository and link it here -->

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [License](#license)
- [Finish](#Finish)

## Introduction

`fn-curl` is a dynamic-link library (DLL) designed to redirect the Fortnite launcher to a custom hybrid server backend. This allows you to customize the behavior of the launcher and potentially integrate additional features into the Fortnite experience.

## Features

- Redirect the Fortnite launcher to a custom hybrid server backend.
- Customize launcher behavior and interactions.
- Potential for integrating additional features into the Fortnite client.

## Installation

To use `fn-curl`, follow these steps:

1. **Download the DLL:** You can download the latest release of the DLL from the [Releases](https://github.com/yourusername/fn-curl/releases) section of this repository.

2. **Edit the DLL:** Once downloaded, extract the `fn-curl-master.rar` file in the file expolorer and open the `.sln` file.

3. **Configuration (if needed):** If you need to customize the redirect backend URL or any other settings, refer to the [Configuration](#configuration) section.

## Usage

After installing the DLL, the redirection will automatically take effect when launching Fortnite through the standard launcher executable. The DLL will intercept the launcher's requests and redirect them to the specified hybrid server backend.

## Configuration

You can configure `fn-curl` by modifying the `curl.h` file. The following options are available:

- Replace `http://127.0.0.1` with the URL of your hybrid server backend.

Example `curl.h`:

```curl.h
http://127.0.0.1 = https://your-fn-hybrid-server-backend.com

## Finish
The final step is to press `Shift + B` in order to compile the DLL. Once the DLL has been successfully built, locate the directory where it was generated and open it using a file explorer.
