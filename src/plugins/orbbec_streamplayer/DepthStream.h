#ifndef DEPTHSTREAM_H
#define DEPTHSTREAM_H

#include <AstraUL/streams/depth_parameters.h>
#include <AstraUL/skul_ctypes.h>
#include <AstraUL/Plugins/stream_types.h>
#include <common/serialization/FrameStreamReader.h>
#include "PlaybackStream.h"
#include <Astra/StreamDescription.h>

using namespace astra::serialization;

namespace astra { namespace plugins { namespace streamplayer
    {

        class DepthStream : public PlaybackStream<astra_imageframe_wrapper_t>
        {
        public:
            DepthStream(FrameStreamReader& streamParser,
                             PluginServiceProxy& pluginService,
                             astra_streamset_t streamSet)
                             : PlaybackStream(streamParser, pluginService, streamSet, StreamDescription(
                                  ASTRA_STREAM_DEPTH,
                                  DEFAULT_SUBTYPE)) { }
            virtual ~DepthStream() {}

            virtual astra_status_t on_open() override
            {
                refresh_conversion_cache(1.02259994,
                                         0.796615660,
                                         320,
                                         240);

                return ASTRA_STATUS_SUCCESS;
            }

            void on_get_parameter(astra_streamconnection_t connection,
                                  astra_parameter_id id,
                                  astra_parameter_bin_t& parameterBin) override
            {
                switch (id)
                {
                case ASTRA_PARAMETER_DEPTH_CONVERSION_CACHE:
                {
                    size_t resultByteLength = sizeof(conversion_cache_t);

                    astra_parameter_data_t parameterData;
                    astra_status_t rc = get_pluginService().get_parameter_bin(resultByteLength,
                                                                                 &parameterBin,
                                                                                 &parameterData);
                    if (rc == ASTRA_STATUS_SUCCESS)
                    {
                        memcpy(parameterData, &m_conversionCache, resultByteLength);
                    }

                    break;
                }
                default:
                    PlaybackStream::on_get_parameter(connection, id, parameterBin);
                    break;
                }
            }

        private:
            void refresh_conversion_cache(float horizontalFov,
                                          float verticalFov,
                                          int resolutionX,
                                          int resolutionY)
            {
                m_conversionCache.xzFactor = tan(horizontalFov / 2) * 2;
                m_conversionCache.yzFactor = tan(verticalFov / 2) * 2;
                m_conversionCache.resolutionX = resolutionX;
                m_conversionCache.resolutionY = resolutionY;
                m_conversionCache.halfResX = m_conversionCache.resolutionX / 2;
                m_conversionCache.halfResY = m_conversionCache.resolutionY / 2;
                m_conversionCache.coeffX = m_conversionCache.resolutionX / m_conversionCache.xzFactor;
                m_conversionCache.coeffY = m_conversionCache.resolutionY / m_conversionCache.yzFactor;
            }

            conversion_cache_t m_conversionCache;
        };

}}}


#endif /* DEPTHSTREAM_H */