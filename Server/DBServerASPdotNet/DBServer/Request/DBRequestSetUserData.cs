﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

using System.Web.Http;

namespace DBServer.Request
{
    public class DBRequestSetUserData
    {
    }

    public class DBRequestSetUserDataController : ApiController
    {
        [Route("Request/DBRequestSetUserData")]
        [HttpPost]
        public async Task<DB_RES_GET_USER_INFO> Process(DB_REQ_GET_USER_INFO requestPacket)
        {
        }
    }
}