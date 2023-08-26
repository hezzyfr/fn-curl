# fn-curl: Fortnite Launcher Redirect DLL

![Project Logo](logo.png) <!-- If you have a logo, place it in the repository and link it here -->

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [License](#license)

## Introduction

`fn-curl` is a dynamic-link library (DLL) designed to redirect the Fortnite launcher to a custom hybrid server backend. This allows you to customize the behavior of the launcher and potentially integrate additional features into the Fortnite experience.

![Screenshot](screenshot.png) <!-- If you have relevant screenshots, include them to provide visual context -->

## Features

- Redirect the Fortnite launcher to a custom hybrid server backend.
- Customize launcher behavior and interactions.
- Potential for integrating additional features into the Fortnite client.

## Installation

To use `fn-curl`, follow these steps:

1. **Download the DLL:** You can download the latest release of the DLL from the [Releases](https://github.com/yourusername/fn-curl/releases) section of this repository.

2. **Place the DLL:** Once downloaded, place the `fn-curl.dll` file in the same directory as the Fortnite launcher executable.

3. **Configuration (if needed):** If you need to customize the server backend URL or any other settings, refer to the [Configuration](#configuration) section.

## Usage

After installing the DLL, the redirection will automatically take effect when launching Fortnite through the standard launcher executable. The DLL will intercept the launcher's requests and redirect them to the specified hybrid server backend.

## Configuration

You can configure `fn-curl` by modifying the `config.ini` file. The following options are available:

- `server_backend_url`: The URL of your hybrid server backend.

Example `config.ini`:

```ini
[General]
server_backend_url = https://your-fn-hybrid-server.com
