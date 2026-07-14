#include "FileCategoryLibrary/FileCategory.h"

#include <algorithm>
#include <cctype>
#include <unordered_map>

namespace file_category
{
    // Get category using the file extension
    std::string getCategory(const std::string& extension)
    {
        // Copy extension so it can be changed
        std::string normalizedExtension = extension;

        // Make all extension letters lowercase
        std::transform(
            normalizedExtension.begin(),
            normalizedExtension.end(),
            normalizedExtension.begin(),
            [](unsigned char character)
            {
                // Change one character to lowercase
                return static_cast<char>(
                    std::tolower(character));
            });

        // List of extensions and what category they belong
        static const std::unordered_map<std::string, std::string> categories{
            // Image file types
            {".jpg", "Images"},
            {".jpeg", "Images"},
            {".png", "Images"},

            // Document file types
            {".pdf", "Documents"},
            {".txt", "Documents"},

            // Video and movie file types
            {".mp4", "Videos"},
            {".mkv", "Videos"},
            {".avi", "Videos"},
            {".mov", "Videos"},
            {".m4v", "Videos"},
            {".wmv", "Videos"},
            {".webm", "Videos"},
            {".mpeg", "Videos"},
            {".mpg", "Videos"},

            // Archive file types
            {".zip", "Archives"}
        };

        // Search map for matching extension
        const auto result =
            categories.find(normalizedExtension);

        // If extension was found return its category
        if (result != categories.end())
        {
            return result->second;
        }

        // Anything not in map goes into Other
        return "Other";
    }
}
