#include "FileCategoryLibrary/FileCategory.h"

#include <algorithm>
#include <unordered_map>

namespace file_category
{
    std::string getCategory(const std::string& extension)
    {
        std::string normalizedExtension = extension;

        std::transform(
            normalizedExtension.begin(),
            normalizedExtension.end(),
            normalizedExtension.begin(),
            [](unsigned char character)
            {
                return static_cast<char>(std::tolower(character));
            });

        static const std::unordered_map<std::string, std::string> categories{
            {".jpg", "Images"},
            {".jpeg", "Images"},
            {".png", "Images"},
            {".pdf", "Documents"},
            {".txt", "Documents"},
            {".mp4", "Videos"},
            {".mkv", "Videos"},
            {".zip", "Archives"}
        };

        const auto result = categories.find(normalizedExtension);

        if (result != categories.end())
        {
            return result->second;
        }

        return "Other";
    }
}